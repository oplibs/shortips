#!/usr/bin/env python
# -*- coding: utf-8 -*-

from s001twosum import Sol001
from s003substring import Sol003

from base.cases import CaseLoader;

class Solution(object):
    __slots__ = ['caseloader']
    def __init__(self):
        pass

    def runAllCases(self, filename, algo):
        # ncount=0;
        self.caseloader = CaseLoader(filename);

        handle = self.caseloader.getHandle();
        for line in handle.readlines():
            line = line.strip();
            print 'current case is as:{0}'.format(line)
            algo.run(line);

if __name__!="main":
    action = str.strip(raw_input('Please input the question number (Input q to quit): '))
    if action== 'q':
        print "quit"
    else:
        classname = 'Sol'+action
        filename = './tests/leet'+action
        algo = eval(classname)()
        sol = Solution();
        sol.runAllCases(filename, algo);
