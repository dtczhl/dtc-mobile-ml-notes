import argparse
import os
from os.path import isfile, join

pathPrefix = '/pcl/lib/'

parser = argparse.ArgumentParser()
parser.add_argument('dirname', help='lib directory')

args = parser.parse_args()
print('Processing librarys under ' + args.dirname)

onlyfiles = [f for f in os.listdir(args.dirname) if isfile(join(args.dirname, f))]

onlyfiles.sort()

print()
for f in onlyfiles:
    f_name = f[:f.find('.')]
    print(f_name, end=' ')
print()
print()

for f in onlyfiles:
    f_name = f[:f.find('.')]
    print('add_library(' + f_name + ' STATIC IMPORTED)')
    print('set_target_properties(' + f_name + ' PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}' + pathPrefix + f + ')')
    print('')
