from pprint import pprint

precedence = {
    None: 0,
    '+': 1,
    '-': 1,
    '*': 2,
    '/': 2,
}

def new_ast():
    return {
        'operand1': None,
        'operand2': None,
        'operator': None,
        'parent': None
    }

def build_ast(expression, st = 0, end=-1):
    """
    輸入一個四則運算表達式，回傳一個 AST 節點。
    """
    ast = new_ast()
    ast['parent'] = ast
    operand = ''
    current = ast
    i = st
    end = len(expression) if end == -1 else end
    while i < end:
        char = expression[i]
        if char.isalnum():
            operand += char
        elif char == '(':
            # 尋找結束的 ) 並且將這一段分開遞迴處理
            j = i + 1
            cnt = 1
            while j < end:
                if expression[j] == '(':
                    cnt += 1
                elif expression[j] == ')':
                    cnt -= 1
                if cnt == 0:
                    operand = build_ast(expression, i + 1, j)
                    operand['parent'] = current
                    break
                j += 1
            i = j + 1
            continue
        else:
            if precedence[current['operator']] == 0:
                current['operator'] = char
                current['operand1'] = operand
            elif precedence[current['operator']] < precedence[char]:
                # 例如現在是 5 + 3         *            2
                #    current(    operand)  operator     something_else
                current['operand2'] = new_ast()
                current['operand2']['parent'] = current
                current = current['operand2']
                current['operand1'] = operand
                current['operator'] = char
                # 新增新的 node，將新的 node 放到舊的 node 的 operand2 位
            else:
                # 例如現在是 5 * 3         +         2
                #    current(    operand)  operator  something_else
                some_ast = new_ast()
                some_ast['operand1'] = current
                some_ast['operator'] = char
                if current == ast:
                    some_ast['parent'] = current['parent']
                    ast = some_ast
                else:
                    some_ast['parent'] = some_ast
                current['parent']['operand2'] = some_ast
                current['operand2'] = operand
                current['parent'] = some_ast
                current = some_ast
                # 新增一個新的 node，將舊的 node 放到新的 node 的 operand1 位；
                # 將 current 設爲新的 node
            operand = ''
        i += 1
    if current['operand1'] == None and isinstance(operand, dict):
        # 如果表達式是只有括號，那麼就直接回傳 operand
        return operand
    current['operand2'] = operand
    return ast

def print_ast(ast, tab = 0):
    if isinstance(ast, str):
        print(' ' * (tab - 1) * 2, ast)
        return
    print(' ' * tab * 2, ast['operator'])
    print_ast(ast['operand1'], tab + 1)
    print_ast(ast['operand2'], tab + 1)

def prefix(ast):
    if isinstance(ast, str):
        print(ast, end='')
        return
    print(ast['operator'], end='')
    prefix(ast['operand1'])
    prefix(ast['operand2'])

def postfix(ast):
    if isinstance(ast, str):
        print(ast, end='')
        return
    postfix(ast['operand1'])
    postfix(ast['operand2'])
    print(ast['operator'], end='')

ast = build_ast(input())
prefix(ast)
print()
postfix(ast)
print()
