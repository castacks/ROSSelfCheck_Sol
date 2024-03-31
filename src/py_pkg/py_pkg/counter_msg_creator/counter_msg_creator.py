
from msg_interfaces.msg import Counter

class CounterMsgCreator(object):
    def __init__(self, name: str):
        super().__init__()

        self.name = name
        self.count = 0

    def create(self):
        msg = Counter()
        msg.name = self.name
        msg.count = self.count
        self.count += 1

        return msg
