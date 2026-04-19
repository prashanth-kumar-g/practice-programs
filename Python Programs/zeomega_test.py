def count_palindromes(mod_value, s):
    n = len(s)
    count = 1

    for i in range(n // 2):
        left = s[i]
        right = s[n - 1 - i]

        # Case 1: both are letters
        if left != '?' and right != '?':
            if left != right:
                return 0   # cannot form palindrome

        # Case 2: both are '?'
        elif left == '?' and right == '?':
            count *= 26

        # Case 3: one is '?' and other is letter
        else:
            count *= 1   # optional, for clarity

    # Middle character (for odd length)
    if n % 2 == 1 and s[n // 2] == '?':
        count *= 26

    # Final modulo
    return count % mod_value


# Input
mod_value = int(input().strip())
s = input().strip()

# Output
print(count_palindromes(mod_value, s))
