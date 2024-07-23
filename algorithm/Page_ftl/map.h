#include "../../include/container.h"
#include "../../interface/interface.h"

#define BENCH_JY 0 
//0 is zip08, 1 is zip11, 2 is random

#define MAX_STREAM 5
typedef struct page_map_body{
	uint32_t *mapping;
	bool isfull;
	uint32_t assign_page;

	/*segment is a kind of Physical Block*/
	__segment *reserve[MAX_STREAM];//for gc
	__segment *active[MAX_STREAM]; //for gc
}pm_body;


void page_map_create();
uint32_t page_map_assign(KEYT *lba, uint32_t max_idx);
uint32_t page_map_pick(uint32_t lba);
uint32_t page_map_trim(uint32_t lba);
uint32_t page_map_gc_update(KEYT* lba, uint32_t idx);
void page_map_free();
