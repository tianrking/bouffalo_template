import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/w0x7ce/Desktop/microros_ws/firmware/dev_ws/install/ament_lint_cmake'
