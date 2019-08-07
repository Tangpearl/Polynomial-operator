#include<stdio.h>
#include<malloc.h>
#include<math.h>
struct polynomial
{
             double a;
             int k;
             struct polynomial *next;
};
struct polynomial *Creat(struct polynomial *head)
{
             struct polynomial *p,*q;
             p=head;
             if(head!=NULL)
             {
                          while(p!=NULL)
                          {
                                  q=p->next;
                                  free(p);
                                  p=q;
                          }
             }
             head=(struct polynomial*)malloc(sizeof(struct polynomial));
             head->next=NULL;
             return head;
}
struct polynomial *polyinsert(struct polynomial *head)
{
   int e;
   double c;
   struct polynomial *q,*s,*z;
   scanf("%lf%d",&c,&e);
   head=Creat(head);
   head->next=NULL;
   s=head->next;
   z=head;
   while(!((c==0)&&(e==0)))
   {
                q=(struct polynomial*)malloc(sizeof(struct polynomial));
                q->a=c;
                q->k=e;
                while((s!=NULL)&&((q->k)<(s->k)))
                {
                             z=s;
                             s=s->next;
                }
               if((s!=NULL)&&((q->k)==(s->k)))
                          s->a=s->a+q->a;
               else
                {
                          z->next=q;
                          q->next=s;
                }
                s=head->next;
                z=head;
                scanf("%lf%d",&c,&e);
   }
   return head;
}

void display(struct polynomial **head)
{
             int m;
             struct polynomial *s;
             scanf("%d",&m);
             if(head[m]==NULL)
                          printf("NULL\n");
             else
             {
                          s=(head[m])->next;
                          if(s==NULL)
                                       printf("0.0000\n");
                          else
             {
                          while(s!=NULL)
                          {
                                     if((s->next==NULL)&&(s->a>1e-8))
                                     {
                                                  if(s->k==1)
                                                    printf("%.4lfx",s->a);
                                                  else
                                                  {
                                                               if(s->k==0)
                                                                printf("%.4lf",s->a);
                                                               else
                                                                printf("%.4lfx^%d",s->a,s->k);
                                                  }
                                     }
                                     else if((s->next!=NULL)&&(s->a>1e-8))
                                     {
                                                  if(s->next->a<=1e-8&&s->next->next==NULL)
                                       {
                                                  if(s->k==1)
                                                    printf("%.4lfx",s->a);
                                                  else
                                                  {
                                                  if(s->k==0)
                                                    printf("%.4lf",s->a);
                                                  else
                                                    printf("%.4lfx^%d",s->a,s->k);
                                                  }
                                       }
                                       else
                                       {
                                                    if(s->k==1)
                                                    printf("%.4lfx",s->a);
                                                  else
                                                  {
                                                  if(s->k==0)
                                                    printf("%.4lf",s->a);
                                                  else
                                                    printf("%.4lfx^%d",s->a,s->k);
                                                  }
                                                  if(s->next->a>1e-8)
                                                    printf("+");
                                       }
                                     }
                                     s=s->next;
                          }
             }
                          printf("\n");
             }
}

void listcopy(struct polynomial **head)
{
             int m1,m2;
             scanf("%d%d",&m1,&m2);
             struct polynomial *s,*q,*p;
             head[m2]=Creat(head[m2]);
             p=head[m2];
             s=(struct polynomial *)malloc(sizeof(struct polynomial));
             head[m2]->next=s;
             q=head[m1]->next;
             while(q!=NULL)
             {
                          s->a=q->a;
                          s->k=q->k;
                          p=s;
                          q=q->next;
                          s=(struct polynomial *)malloc(sizeof(struct polynomial));
                          p->next=s;
             }
             free(s);
             p->next=NULL;
}

void listplus(struct polynomial **head)
{
             int m1,m2,m3;
             scanf("%d%d%d",&m1,&m2,&m3);
             head[m3]=Creat(head[m3]);
             struct polynomial *p,*q,*s,*z;
             p=head[m1]->next;
             q=head[m2]->next;
             s=(struct polynomial *)malloc(sizeof(struct polynomial));
             z=head[m3];
             z->next=s;
             while((p!=NULL)&&(q!=NULL))
             {
                          if(p->k==q->k)
                          {
                                       s->k=p->k;
                                       s->a=(p->a)+(q->a);
                                       p=p->next;
                                       q=q->next;
                          }
                          else
                                      {
                                                   if((p->k)>(q->k))
                                                   {
                                                          s->k=p->k;
                                                          s->a=p->a;
                                                          p=p->next;
                                                   }
                                                   else if((p->k)<(q->k))
                                                   {
                                                             s->k=q->k;
                                                             s->a=q->a;
                                                             q=q->next;
                                                   }
                                      }
                          z=s;
                          s=(struct polynomial *)malloc(sizeof(struct polynomial));
                          z->next=s;
             }
             if((p==NULL)&&(q!=NULL))
             {
                          while(q!=NULL)
                          {
                                       s->a=q->a;
                                       s->k=q->k;
                                       q=q->next;
                                       z=s;
                                       s=(struct polynomial *)malloc(sizeof(struct polynomial));
                                       z->next=s;
                          }

             }
             else
             {
                          if((q==NULL)&&(p!=NULL))

                  {
                          while(p!=NULL)
                          {
                                       s->a=p->a;
                                       s->k=p->k;
                                       p=p->next;
                                       z=s;
                                       s=(struct polynomial *)malloc(sizeof(struct polynomial));
                                       z->next=s;
                          }
                   }
                          else if((q==NULL)&&(p==NULL))
                         {
                          free(s);
                          z->next=NULL;
                         }
             }
}

void listsub(struct polynomial **head)
{
             int m1,m2,m3;
             scanf("%d%d%d",&m1,&m2,&m3);
             head[m3]=Creat(head[m3]);
             struct polynomial *p,*q,*s,*z;
             p=head[m1]->next;
             q=head[m2]->next;
             s=(struct polynomial *)malloc(sizeof(struct polynomial));
             z=head[m3];
             z->next=s;
             while((p!=NULL)&&(q!=NULL))
             {
                          if(p->k==q->k)
                          {
                                       s->k=p->k;
                                       s->a=(p->a)-(q->a);
                                       p=p->next;
                                       q=q->next;
                          }
                          else
                                      {
                                                   if((p->k)>(q->k))
                                                   {
                                                          s->k=p->k;
                                                          s->a=p->a;
                                                          p=p->next;
                                                   }
                                                   else if((p->k)<(q->k))
                                                   {
                                                             s->k=q->k;
                                                             s->a=-q->a;
                                                             q=q->next;
                                                   }
                                      }
                          z=s;
                          s=(struct polynomial *)malloc(sizeof(struct polynomial));
                          z->next=s;
             }
             if((p==NULL)&&(q!=NULL))
             {
                          while(q!=NULL)
                          {
                                       s->a=q->a;
                                       s->k=q->k;
                                       q=q->next;
                                       z=s;
                                       s=(struct polynomial *)malloc(sizeof(struct polynomial));
                                       z->next=s;
                          }

             }
             else
             {
                          if((q==NULL)&&(p!=NULL))

                  {
                          while(p!=NULL)
                          {
                                       s->a=p->a;
                                       s->k=p->k;
                                       p=p->next;
                                       z=s;
                                       s=(struct polynomial *)malloc(sizeof(struct polynomial));
                                       z->next=s;
                          }
                   }
                          else if((q==NULL)&&(p==NULL))
                         {
                          free(s);
                          z->next=NULL;
                         }
             }
}

void polyevalavition (struct polynomial **head)
{
             struct polynomial *p;
             int m,i;
             double a,b;
             b=0;
             scanf("%d%lf",&m,&a);
             p=head[m]->next;
             while(p!=NULL)
             {
                    b=(p->a)*pow(a,p->k)+b;
                    p=p->next;
             }
             printf("%.4lf\n",b);
}

void clearpoly(struct polynomial **head)
{
             struct polynomial *p,*s;
             int m;
             scanf("%d",&m);
             s=head[m]->next;
             p=s;
             while(p!=NULL)
             {
                          p=s->next;
                          free(s);
                          s=p;
             }
             head[m]->next=NULL;
}

void deletepoly(struct polynomial **head)
{
             struct polynomial *p,*s;
             int m;
             scanf("%d",&m);
             p=head[m];
             while(p!=NULL)
             {
                          s=p->next;
                          free(p);
                          p=s;
             }
             head[m]=NULL;
}

void modify(struct polynomial **head)
{
             struct polynomial *p,*s,*q;
             int m,t,k;
             double a;
             scanf("%d%d",&m,&t);
             p=head[m]->next;
             q=head[m];
             if(t==1)
             {
                          scanf("%lf%d",&a,&k);
                          s=(struct polynomial *)malloc(sizeof(struct polynomial));
                          s->a=a;
                          s->k=k;
                          while((p!=NULL)&&(p->k>s->k))
                                       {
                                                                 q=p;
                                                                 p=p->next;
                                       }
                                       if(p!=NULL)
                                       {
                                                    if(p->k==s->k)
                                                                 p->a=p->a+s->a;
                                                    else
                                                    {
                                                                 if(p->k<s->k)
                                                                 {
                                                                              q->next=s;
                                                                              s->next=p;
                                                                 }
                                                    }
                                       }
                                       else
                                       {
                                                    if(p==NULL)
                                                    {
                                                                 q->next=s;
                                                                 s->next=NULL;
                                                    }
                                       }
             }
             else
             {
                          if(t==2)
                          {
                                       scanf("%d",&k);
                                       while((p->k>k)&&(p!=NULL))
                                                    p=p->next;
                                       if(p!=NULL&&(p->k==k))
                                                    p->a=0;
                          }
                          else
                          {
                                       scanf("%lf%d",&a,&k);
                                       while(p->k>k)
                                                    p=p->next;
                                       p->a=a;
                          }
             }

}

void differpoly(struct polynomial **head)
{
             struct polynomial *p,*q,*s;
             int m1,m2;
             scanf("%d%d",&m1,&m2);
             p=head[m1]->next;
             q=(struct polynomial *)malloc(sizeof(struct polynomial));
             head[m2]=Creat(head[m2]);
             head[m2]->next=q;
             while(p!=NULL)
             {
                          if(p->k==0)
                                       p=p->next;
                          else
                          {
                                       q->k=(p->k)-1;
                                       q->a=(p->a)*(p->k);
                                       p=p->next;
                                       s=q;
                                       q=(struct polynomial *)malloc(sizeof(struct polynomial));
                                       s->next=q;
                          }
             }
             s->next=NULL;
             free(q);
}

void integration(struct polynomial **head)
{
             struct polynomial *p,*q,*s;
             int m1,m2;
             scanf("%d%d",&m1,&m2);
             p=head[m1]->next;
             q=(struct polynomial *)malloc(sizeof(struct polynomial));
             head[m2]=Creat(head[m2]);
             head[m2]->next=q;
             while(p!=NULL)
             {
                          if(p->k==0)
                          {
                                       q->a=p->a;
                                       q->k=1;
                          }
                          else
                          {
                                       q->a=(p->a)/(p->k+1);
                                       q->k=p->k+1;
                          }
                          p=p->next;
                          s=q;
                          q=(struct polynomial *)malloc(sizeof(struct polynomial));
                          s->next=q;
             }
             s->next=NULL;
             free(q);
}

double zhijisuan(struct polynomial *z,double x)
{
             struct polynomial *p;
             p=z->next;
             double e=0;
             while(p!=NULL)
             {
                       e=e+(p->a)*pow(x,p->k);
                       p=p->next;
             }
             return (e);
}

void definiteintegral(struct polynomial **head)
{
             struct polynomial *p,*q,*s;
             struct polynomial *z=NULL;
             int m;
             double x1,x2,e1,e2,e3;
             scanf("%d%lf%lf",&m,&x1,&x2);
             p=head[m]->next;
             z=Creat(z);
             q=(struct polynomial *)malloc(sizeof(struct polynomial));
             z->next=q;
             while(p!=NULL)
             {
                           if(p->k==0)
                          {
                                       q->a=p->a;
                                       q->k=1;
                          }
                          else
                          {
                                       q->a=(p->a)/(p->k+1);
                                       q->k=p->k+1;
                          }
                          p=p->next;
                          s=q;
                          q=(struct polynomial *)malloc(sizeof(struct polynomial));
                          s->next=q;
             }
             s->next=NULL;
             free(q);
             e1=zhijisuan(z,x1);
             e2=zhijisuan(z,x2);
             e3=e2-e1;
             printf("%.4lf\n",e3);
}

void multiploy(struct polynomial **head)
{
             struct polynomial *p,*q,*s,*z,*m;
             int m1,m2,m3;
             scanf("%d%d%d",&m1,&m2,&m3);
             head[m3]=Creat(head[m3]);
             s=(struct polynomial *)malloc(sizeof(struct polynomial));
             head[m3]->next=s;
             p=head[m1]->next;
             q=head[m2]->next;
             while(q!=NULL)
             {
                                       s->a=p->a*q->a;
                                       s->k=p->k+q->k;
                                       z=s;
                                       s=(struct polynomial *)malloc(sizeof(struct polynomial));
                                       z->next=s;
                                       q=q->next;
             }
             z->next=NULL;
             free(s);
             p=p->next;
             q=head[m2]->next;
             s=head[m3]->next;
             z=head[m3];
             while(p!=NULL)
             {
                          while(q!=NULL)
                          {
                                      m=(struct polynomial *)malloc(sizeof(struct polynomial));
                                      m->a=q->a*p->a;
                                      m->k=q->k*p->k;
                                      while(s!=NULL)
                                      {
                                                   if(m->k<s->k)
                                                   {
                                                                z=s;
                                                                s=s->next;
                                                   }
                                                   else
                                                   {
                                                                if(m->k==s->k)
                                                                {
                                                                             s->a=s->a+m->a;
                                                                }
                                                                else
                                                                {
                                                                             z->next=m;
                                                                             m->next=s;
                                                                }
                                                   }
                                      }
                                      if(s==NULL)
                                      {
                                                   z->next=m;
                                                   m->next=NULL;
                                      }
                                      z=head[m3];
                                      s=head[m3]->next;
                                      q=q->next;
                          }
                          p=p->next;
                          q=head[m2]->next;
             }
}
void main()
{
             struct polynomial *p[10]={NULL};
             struct polynomial **q;
             int m1;
             q=p;
             int w;
             scanf("%d",&w);
             while(w!=0)
             {
                         switch(w)
                 {
                          case 1:
                                       {
                                                    scanf("%d",&m1);
                                                    q[m1]=polyinsert(q[m1]);
                                                    break;
                                       }
                          case 2:
                                       {
                                                    display(q);
                                                    break;
                                       }
                          case 3:
                                       {
                                                    listcopy(q);
                                                    break;
                                       }
                          case 4:
                                       {
                                                    listplus(q);
                                                    break;
                                       }
                          case 5:
                                       {
                                                    listsub(q);
                                                    break;
                                       }
                          case 6:
                                       {
                                                    polyevalavition(q);
                                                    break;
                                       }
                          case 7:
                                       {
                                                    deletepoly(q);
                                                    break;
                                       }
                          case 8:
                                       {
                                                    clearpoly(q);
                                                    break;
                                       }
                          case 9:
                                       {
                                                    modify(q);
                                                    break;
                                       }
                          case 10:
                                       {
                                                    differpoly(q);
                                                    break;
                                       }
                          case 11:
                                       {
                                                    integration(q);
                                                    break;
                                       }
                          case 12:
                                       {
                                                    definiteintegral(q);
                                                    break;
                                       }
                          case 13:
                                       {
                                                    multiploy(q);
                                                    break;
                                       }
                          case 14:
                          case 15:
                          case 16:
                          case 17:
                          case 18:
                          case 19: break;
                 }
                 scanf("%d",&w);
             }
}
