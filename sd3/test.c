#include "header.h"


int main() 
{
	void* a;
	a = (void*)InitQ(sizeof(TCoada));
TC tree = (TC)Initializare(&tree);
add(tree,".+",'e');
add(tree,"_..",'m');
add(tree,".+_",'a');
add(tree,"_.+",'T');
add(tree,".+.",'t');
add(tree,"&",'i');
add(tree,"_.+&",'.');
add(tree,"_..&",'r');
add(tree,"&.",'u');
	TC x = tree;
	/*while (x != NULL) {
	IntrQ(a,x); 
	x = x->jos;
	}
	x = tree->jos->urm;
	while (x != NULL){
	IntrQ(a,x);
	 x = x->jos;
	} */
	Show(tree,a);
	return 0;
}
