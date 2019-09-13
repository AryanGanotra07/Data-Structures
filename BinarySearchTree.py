class Node:

    def __init__(self,key):
        self.right = None
        self.left = None
        self.val = key

    def insert(root,node):
        if root is None:
            root = node
        else:
            if node.val > root.val:
                if root.right is None:
                    root.right = node
                else:
                    insert(root.right, node)
            else:
                if root.left is None:
                    root.left = node
                else:
                    insert(root.left, node)

    def search(root,key):
        ##when root is null or key is present
        if root is None or root.val==key:
            return root
        else:
            if key > root.val:
                ##when root value is smaller
                return search(root.right, key)
            ##when root value is larger
            return search(root.left,key)

    def inorder(root):
        if root is not None:
            inorder(root.left)
            print (root.val)
            inorder(root.right)

    # Returns the node with min value in the tree
    def minValue(node):
        current = node
        #looping down to leftmost leaf
        while(current.left is not None):
            current = current.left
        return current 

   #Given a binary search tree,key . Deletes the key from the binary search tree.
    def delete(root, key):
        if root is None:
            return root
        #if key is larger, then it lies in right subtree  
        if key > root.val:
            root.right = delete(root.right,key)
        #if key is smaller, then it lies in left subtree
        elif key < root.val:
            root.left = delete(root.left,key)
        #key is same as the root's value
        else:
            #node with one child node or none child node
            if root.left is None:
                temp = root.right
                root = None
                return temp
            elif root.right is None:
                temp = root.left
                root = None
                return temp
            #Node with two child node
            temp = minValue(root.right) #Get inorder successor's
            root.val = temp.val
            #Delete the inorder successor
            root.right = delete(root.right,temp.val)
        
        
                


    
