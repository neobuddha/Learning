"""
This file has code for a recursive sum program
"""

__author__="Prabhat Singh"



class learnDictionary:
    hashTable = {}

    def addKey(self, key, value):
        self.hashTable[key] = value

    def getValue(self, key):
        if key in self.hashTable:
            return self.hashTable[key]
        else:
            print "Key: ", key, "Not Found"
    

def main():
    print "Learning Hashtable/Dictionary in Python"

    obj = learnDictionary()

    obj.addKey('Mango', 1)
    obj.addKey('Apple', 2)
    obj.addKey('Guava', 3)
    obj.addKey('Grapes', 4)
    obj.addKey('Prune', 5)
    obj.addKey('Plum', 6)
    obj.addKey('Kiwi', 7)
    obj.addKey('Pears', 8)
    obj.addKey('Melon', 9)

    print "Mango" , obj.getValue('Mango')
    print "Plum" , obj.getValue('Plum')

    obj.getValue('Carrot')


if __name__=="__main__":
    main()

