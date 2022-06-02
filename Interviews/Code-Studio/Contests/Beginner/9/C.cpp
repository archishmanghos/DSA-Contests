/************************************************
   
   Following is the linkedList class structure:

   class List {
    public:
        int data;
        List *next;
        List() {};
        List(int v){
            data = v;
            next = NULL;
        };
   };

*************************************************/

int findCaptian(List *head) {
   int n = 0;
   List *temp = head;
   while(temp != NULL) n += 1, temp = temp->next;
   int cnt = 0;
   temp = head;
   while(cnt < n / 2) cnt += 1, temp = temp->next;
   return temp->val;
}