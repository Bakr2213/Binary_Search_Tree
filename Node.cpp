#include "Node.h"
#include <cstddef>

Node::Node(int value)
{
	data = value;
	right = left = NULL;
}
