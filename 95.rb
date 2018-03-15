# 95. Unique Binary Search Trees II
# link: https://leetcode.com/problems/unique-binary-search-trees-ii/description/
# status: AC
# 2018.03.15


def add_offset(node, min_val)
  new_node = node.clone
  new_node.val += (min_val - 1)
  if node.left == nil && node.right == nil
    return new_node
  end
  
  if new_node.left
    new_node.left = add_offset(new_node.left, min_val)
  end
  if new_node.right
    new_node.right = add_offset(new_node.right, min_val)
  end
  return new_node
end

def add_offsets(trees, min_val)
  trees.map do |tree|
    add_offset(tree.clone, min_val)
  end
end
def generate_trees(n)
  dp = [[], [TreeNode.new(1)]]

  (2..n).each do |i|
    (1..i).each do |j|
      if dp[i] == nil
        dp[i] = []     
      end
      left_size = j - 1
      right_size = i - j
      if left_size == 0
        add_offsets(dp[i - 1], j + 1).each do |tree|
          root = TreeNode.new(j)
          root.right = tree
          dp[i].push(root)
        end
        next
      elsif right_size == 0
        add_offsets(dp[i - 1], 1).each do |tree|
          root = TreeNode.new(j)
          root.left = tree
          dp[i].push(root)
        end
        next
      end

      all_pairs = add_offsets(dp[left_size], 1).product(add_offsets(dp[right_size], j + 1))
      all_pairs.each do |left_tree, right_tree|
        root = TreeNode.new(j)
        root.left = left_tree
        root.right = right_tree
        dp[i].push(root)
      end
    end
  end
  return dp[n]
end
