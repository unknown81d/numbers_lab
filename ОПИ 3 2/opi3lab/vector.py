class Vector:
    def __init__(self):
        self.length = 0
        self.capacity = 1
        self.array = self.make_array(self.capacity)

    def __len__(self):
        return self.length

    def __getitem__(self, index):
        if not 0 <= index < self.length:
            return IndexError('Index is out of range!')
        return self.array[index]

    def append(self, element):
        if self.length == self.capacity:
            self._resize(2 * self.capacity)
        self.array[self.length] = element
        self.length += 1

    def _resize(self, new_capacity):
        new_array = self.make_array(new_capacity)
        for i in range(self.length):
            new_array[i] = self.array[i]
        self.array = new_array
        self.capacity = new_capacity

    def make_array(self, capacity):
        return [None] * capacity

    def __iter__(self):
        for index in range(self.length):
            if not 0 <= index < self.length:
                return IndexError('Index is out of range!')
            yield self.array[index]