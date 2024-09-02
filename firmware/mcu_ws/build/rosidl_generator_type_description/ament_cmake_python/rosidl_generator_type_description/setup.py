from setuptools import find_packages
from setuptools import setup

setup(
    name='rosidl_generator_type_description',
    version='4.6.3',
    packages=find_packages(
        include=('rosidl_generator_type_description', 'rosidl_generator_type_description.*')),
)
