#include <stdio.h>

#include <stdlib.h>


struct Node{


    int data;
    struct Node *left;
    struct Node *right;


};


struct Node * createNode (int data){






    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode-> left = NULL;
    newNode-> right = NULL;
    return newNode;

}


struct Node * insert ( struct Node *  root, int data){

if (root==NULL){



    return createNode(data);


}



if(data < root-> data){

////Move to the left vro cause its less

root->left = insert(root-> left, data);



} else if(data> root->data){


    ///Move to the right
    root-> right = insert(root->right,data);
}


return root;

}



struct Node * search(struct Node * root, int data){
if( root == NULL || root->data== data)
{

/// if root is NULL and the data is already == data which are looking for then
    return root;
}
if (data< root->data){

    /// move to the left

return search(root->left,data); //search the left for data

}

return search(root->right,data);




}

void inOrderTraversal(struct Node * root){




    if(root != NULL){

        inOrderTraversal(root->left);
        printf("%d", root->data);
        inOrderTraversal(root->right);



    }
}








int main(){






    struct Node  * root = NULL;
    int n, value;

    printf("Enter the number of elements to insert");
    scanf("%d",&n);


    for (int i = 0 ; i < n ; i++){

        printf("Enter the value %d :", i+1 );
        scanf("%d", &value);
        root = insert(root,value);

    }


printf("In-Order Traversal:");

inOrderTraversal(root);

printf("\n");


printf("Enter a value to search:");
scanf("%d" , &value);

struct Node * result = search(root, value);

if(result!=NULL){


    printf("FOUND %d in the BST" , value);

}else {



    printf("Not Found");
}
    


}

