class BTreeNode:
    def __init__(self, t, leaf=False):
        self.t = t
        self.leaf = leaf
        self.keys = []
        self.children = []

    def split_child(self, i, child):
        new_child = BTreeNode(t=self.t, leaf=child.leaf)
        self.children.insert(i + 1, new_child)
        new_child.keys = child.keys[self.t:]
        child.keys = child.keys[:self.t]
        if not child.leaf:
            new_child.children = child.children[self.t:]
            child.children = child.children[:self.t]

    def insert_nonfull(self, k):
        i = len(self.keys) - 1
        if self.leaf:
            self.keys.append(0)
            while i >= 0 and k < self.keys[i]:
                self.keys[i + 1] = self.keys[i]
                i -= 1
            self.keys[i + 1] = k
        else:
            while i >= 0 and k < self.keys[i]:
                i -= 1
            i += 1
            if len(self.children[i].keys) == (2 * self.t - 1):
                self.split_child(i, self.children[i])
                if k > self.keys[i]:
                    i += 1
            self.children[i].insert_nonfull(k)

    def insert(self, k):
        if len(self.keys) == (2 * self.t - 1):
            new_root = BTreeNode(t=self.t)
            new_root.children.append(self)
            new_root.split_child(0, self)
            new_root.insert_nonfull(k)
            return new_root
        else:
            self.insert_nonfull(k)
            return self

    def search(self, k):
        i = 0
        while i < len(self.keys) and k > self.keys[i]:
            i += 1
        if i < len(self.keys) and k == self.keys[i]:
            return self
        elif self.leaf:
            return None
        else:
            return None if i == len(self.children) else self.children[i].search(k)

    def merge(self, i):
        child = self.children[i]
        sibling = self.children[i + 1]
        child.keys.append(self.keys[i])
        child.keys.extend(sibling.keys)
        if not child.leaf:
            child.children.extend(sibling.children)
        self.keys.pop(i)
        self.children.pop(i + 1)
        return child

    def borrow_from_prev(self, i):
        child = self.children[i]
        sibling = self.children[i - 1]
        child.keys.insert(0, self.keys[i - 1])
        if not child.leaf:
            child.children.insert(0, sibling.children[-1])
            self.keys[i - 1] = sibling.keys.pop(-1)
            if len(sibling.keys) < self.t:
                return sibling
            else:
                return None

    def borrow_from_next(self, i):
        child = self.children[i]
        sibling = self.children[i + 1]
        child.keys.append(self.keys[i])
        if not child.leaf:
            child.children.append(sibling.children[0])
        self.keys[i] = sibling.keys.pop(0)
        if len(sibling.keys) < self.t:
            return sibling
        else:
            return None

    def delete_at_leaf(self, i):
        self.keys.pop(i)
        if len(self.keys) < self.t:
            return self
        else:
            return None

    def delete_at_internal(self, i):
        if self.children[i].leaf:
            predecessor = self.children[i].keys[-1]
            self.keys[i] = predecessor
            self.children[i] = self.children[i].delete(predecessor)
        else:
            predecessor = self.children[i].get_predecessor()
            self.keys[i] = predecessor
            self.children[i].delete(predecessor)

    def delete(self, k):
        i = 0
        while i < len(self.keys) and k > self.keys[i]:
            i += 1
        if i < len(self.keys) and k == self.keys[i]:
            if self.leaf:
                return self.delete_at_leaf(i)
            else:
                return self.delete_at_internal(i)
        elif self.leaf:
            return None
        else:
            child_to_delete = self.children[i]
            if len(child_to_delete.keys) == self.t - 1:
                left_sibling = None if i == 0 else self.children[i - 1]
                right_sibling = None if i == len(self.children) - 1 else self.children[i + 1]
                if left_sibling and len(left_sibling.keys) > self.t - 1:
                    child_to_delete.borrow_from_prev(i)
                elif right_sibling and len(right_sibling.keys) > self.t - 1:
                    child_to_delete.borrow_from_next(i)
                else:
                    if left_sibling:
                        self.children[i - 1] = self.merge(i - 1)
                        child_to_delete = self.children[i - 1]
                    else:
                        self.children[i] = self.merge(i)
                        child_to_delete = self.children[i]
            return child_to_delete.delete(k)
        return None


class BTree:
    def __init__(self, t):
        self.root = BTreeNode(t=t, leaf=True)

    def insert(self, k):
        new_root = self.root.insert(k)
        if new_root:
            self.root = new_root

    def search(self, k):
        return self.root.search(k)

    def delete(self, k):
        self.root.delete(k)
        if len(self.root.keys) == 0 and len(self.root.children) > 0:
            self.root = self.root.children[0]

    def edit(self, old_key, new_key):
        if self.search(old_key) == None:
            print("Key not found in the tree")
            return
        self.delete(old_key)
        self.insert(new_key)


