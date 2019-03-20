for a in range(ord('x'),ord('z')+1):
    for b in range(ord('x'),ord('z')+1):
        if(a!=b):
            for c in range(ord('x'),ord('z')+1):
                if(b!=c and a!=c):
                    if(a!=ord('x') and c!=ord('x') and c!=ord('z')):
                        print ('order is a -- %s\t b -- %s\tc--%s' % (chr(a),chr(b),chr(c)))