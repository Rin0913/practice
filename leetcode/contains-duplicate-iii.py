class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        if valueDiff < 0:
            return False

        bucket_width = valueDiff + 1
        buckets = {}
        
        for i in range(len(nums)):
            bucket_id = nums[i] // bucket_width
            
            if bucket_id in buckets:
                return True
            
            if (bucket_id - 1 in buckets and abs(nums[i] - buckets[bucket_id - 1]) < bucket_width):
                return True
            if (bucket_id + 1 in buckets and abs(nums[i] - buckets[bucket_id + 1]) < bucket_width):
                return True
            
            buckets[bucket_id] = nums[i]
            
            if i >= indexDiff:
                old_bucket_id = nums[i - indexDiff] // bucket_width
                del buckets[old_bucket_id]
        
        return False
