void levelOrder( struct node *root) {
    //queue
    struct node *q[500];
    int front = 0;
    int rear = 0;
    q[rear] = root;
    rear++;
    //run a loop as long queue is not empty
    while(front!=rear){
        struct node *dn = q[front++];
        printf("%d ",dn->data);
        if(dn->left!=NULL){
            q[rear]=dn->left;
            rear++;
        }
        if(dn->right!=NULL){
            q[rear]=dn->right;
            rear++;
        }
        free(dn);
    }
}
