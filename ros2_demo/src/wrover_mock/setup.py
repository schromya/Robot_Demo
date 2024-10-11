from setuptools import find_packages, setup

package_name = 'WRover_Mock'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Wisconsin Robotics',
    maintainer_email='wisconsinrobotics@cae.wisc.edu',
    description='Sets up mock rover',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'Robot = WRover_Mock.Robot:main',
        ],
    },
)
