class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

class List:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, data):
        node = Node(data, self.head)
        self.head = node

    def insert_at_end(self, data):
        if not self.head:
            self.head = Node(data, None)
            return
        current_node = self.head
        while current_node.next:
            current_node = current_node.next
        current_node.next = Node(data, None)

    def append(self, data):
        self.insert_at_end(data)

    def insert_at_index(self, index, data):
        if index == 0:
            self.insert_at_beginning(data)
            return
        current_node = self.head
        current_index = 0
        while current_node.next and current_index < index - 1:
            current_node = current_node.next
            current_index += 1
        node = Node(data, current_node.next)
        current_node.next = node

    def delete_at_index(self, index):
        if index == 0:
            self.head = self.head.next
            return
        current_node = self.head
        current_index = 0
        while current_node.next and current_index < index - 1:
            current_node = current_node.next
            current_index += 1
        current_node.next = current_node.next.next

    def __iter__(self):
        current_node = self.head
        while current_node:
            yield current_node.data
            current_node = current_node.next