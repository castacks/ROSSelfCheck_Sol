
from msg_interfaces.msg import Counter

class CounterMsgCreator(object):
    def __init__(self, name: str, start_count: int = 0):
        super().__init__()

        self.name = name
        self.count = start_count

    def create(self, node):
        msg = Counter()
        msg.stamp = node.get_clock().now().to_msg()
        msg.name = self.name
        msg.count = self.count
        self.count += 1

        return msg
