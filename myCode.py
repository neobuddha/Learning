__author__ = "Prabhat Singh"

def myFunc():
    '''
    :description: Just a testing function for learning Python
    :rtype : Status
    '''

    print 'This is a function call'

    goodFunction ('Input Parameter1', 'Input Parameter2')

    return ('Test')

def goodFunction(param1, param2):
    print 'Call this function from other function'
    print 'param1'
    print 'param2'

if __name__ == '__main__':
    myFunc()