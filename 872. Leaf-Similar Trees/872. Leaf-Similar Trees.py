from binarytree import Node
import typing

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def leafSimilar(self, root1: typing.Optional[TreeNode], root2: typing.Optional[TreeNode]) -> bool:
        def get_leaf_sequence(root):
            if not root:
                return []
            if not root.left and not root.right:
                return [root.val]
            return get_leaf_sequence(root.left) + get_leaf_sequence(root.right)
        
        return get_leaf_sequence(root1) == get_leaf_sequence(root2)

# Definir los árboles de los casos de prueba
root1_1 = Node(3)
root1_1.left = Node(5)
root1_1.right = Node(1)
root1_1.left.left = Node(6)
root1_1.left.right = Node(2)
root1_1.right.left = Node(9)
root1_1.right.right = Node(8)
root1_1.left.right.left = Node(7)
root1_1.left.right.right = Node(4)

root2_1 = Node(3)
root2_1.left = Node(5)
root2_1.right = Node(1)
root2_1.left.left = Node(6)
root2_1.left.right = Node(7)
root2_1.right.left = Node(4)
root2_1.right.right = Node(2)
root2_1.right.right.left = Node(9)
root2_1.right.right.right = Node(8)

root1_2 = Node(1)
root1_2.left = Node(2)
root1_2.right = Node(3)

root2_2 = Node(1)
root2_2.left = Node(3)
root2_2.right = Node(2)

# Crear una instancia de la clase Solution
s = Solution()

# Probar la función con los casos de prueba
output_1 = s.leafSimilar(root1_1, root2_1)
output_2 = s.leafSimilar(root1_2, root2_2)

# Imprimir los resultados
print(output_1)  # Output: True
print(output_2)  # Output: False

# Imprimir los árboles
print("\nÁrbol 1 del caso de prueba 1:")
print(root1_1)

print("\nÁrbol 2 del caso de prueba 1:")
print(root2_1)

print("\nÁrbol 1 del caso de prueba 2:")
print(root1_2)

print("\nÁrbol 2 del caso de prueba 2:")
print(root2_2)