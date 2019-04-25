//伪代码
void midprecreat(BiTree*root,char mid[],char pre[],int lm,int rm,int lp,int rp)
{
    *root=(BiTree)malloc(sizeof(BiTNode));
    (*root)->data=pre[lp];
    (*root)->lchild=NULL;
    (*root)->rchild=NULL;
   int pos=lm;
   while(mid[pos]!=pre[lp])
        pos++;
    int childlen=pos-lm;//用来控制子树在字符串中的范围
    if(pos>lm)//有左子树,递归创建
        midprecreat((&((*root)->lchild)),mid,pre,lm,pos-1,lp+1,lp+childlen);
    if(pos<rm)//有右子树,递创建
        midprecreat((&((*root)->rchild)),mid,pre,pos+1,rm,lp+childlen+1,rp);
}
