#!/usr/bin/env python
# -*- coding: utf-8 -*-

sum=0;
for i in range(1, 1000):
    if i%3==0 or i%5==0:
        print(i);
        sum=sum+i;
print(sum);
