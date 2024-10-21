def count_factors(n):
    count = 0
    # 找出所有因數
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            count += 1
            # 如果 i 和 n // i 不同，說明有另一個因數
            if i != n // i:
                count += 1
    return count

def is_even_factors(n):
    factor_count = count_factors(n)
    return factor_count % 2 == 0

for i in range(1, 100):
    if not is_even_factors(i):
        print(i)
