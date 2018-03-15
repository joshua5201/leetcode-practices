# 96. Unique Binary Search Trees
# link: https://leetcode.com/problems/unique-binary-search-trees/description/
# status: AC
# 2018.03.14

def num_trees(n)
  dp = [1, 1, 2]
  (3..n).each do |i|
    ans = 0
    (1..i).each do |j|
      ans += dp[j - 1] * dp[i - j]
    end
    dp[i] = ans
  end
  return dp[n]
end
