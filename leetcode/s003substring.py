#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Sol003(object):
    def __init__(self):
        pass

    def run(self, casedata):
        print "result is:"
        print self.execute(casedata);

    def execute(self, s):
        if len(s)<2:
            return len(s);
        start=-1
        end=0
        res=0
        charDict={}

        for end in range(len(s)):
            curc = s[end]
            if curc in charDict:
                res = max(end-start-1, res)
                while start<end:
                    startc=s[start]
                    start=start+1;
                    if startc in charDict:
                        del(charDict[startc]);
                    if startc==curc:
                        break;
            else:
                charDict[curc] = 0;
        print start,end
        res = max(end-start, res)
        return res
