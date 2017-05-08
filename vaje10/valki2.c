#include<stdio.h>

struct vagon{
	int id;
	struct vagon* next;	
};

struct lokomotiva{
	int id;
	struct lokomotiva* next;
	struct vagon* nextVagon;	
};

int main(){
	int ukazov, i;
	scanf("%d", &ukazov);

	struct lokomotiva prva;

	for(i = 0; i < ukazov; i++){
		int lid, vid;
		scanf("%d %d", &lid, &vid);
		if(i == 0){
			prva.id = lid;
			struct vagon naslednji;
			naslednji.id = vid;			
			prva.nextVagon = *naslednji;
		}else{
			
			struct lokomotiva t;
			int found = 0;
			while(t.next != NULL){
				if(&(t.next).id == lid){
					
					found = 1;
					break;
				}
				t = &(t.next);
			}
			if(found == 0){
				struct lokomotiva l;
				l.id = lid;
				t.next = *l;
				struct vagon v;
				v.id = vid;
				l.nextVagon = *v;				
			}
		}		
	}

	struct lokomotiva t = prva;
	while(t.next != NULL){
		printf("%d\n", t.id);
		t = &(t.next);
	}
}
