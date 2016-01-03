#[SerializeAndDeserializeBinaryTree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
######No: `297`
######Tag: `Tree`
######Difficulty: `Medium`
This is a difficult question for me. Since the C++ provide very back string support. 
The idea for the serialization is that we use depth first search and using # to represent the NULL pointer.
That done.

And for deserialize, first we need to split the string and put it into a deque. However, the c++ does not
support the string split. Therefore, we need to use the istringstream to do this. The Reason we use deque
is that we need to get element by it input sequence.
