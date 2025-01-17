from glob import glob
import os
from setuptools import find_packages, setup

package_name = 'py_exe'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='yaoyuh',
    maintainer_email='yaoyuh@andrew.cmu.edu',
    description='A python publisher for ROS Skill Self-Check',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'py_exe = py_exe.py_exe:main',
        ],
    },
)
