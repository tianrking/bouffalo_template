from setuptools import find_packages
from setuptools import setup

setup(
    name='rcutils',
    version='6.7.1',
    packages=find_packages(
        include=('rcutils', 'rcutils.*')),
)
