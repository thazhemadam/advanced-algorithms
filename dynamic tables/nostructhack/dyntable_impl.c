#include "dyntable_impl.h"

/*
 * Initialize a dynamic table.
 * Returns a pointer that points to the newly created dynamic_table
 * @n:      initial number of elements the dynamic table should be able to hold without being resized 
 */
void* make_new_dynamic_table(int n)
{
        struct dyntable* dt = malloc(sizeof(struct dyntable));
        dt->data = malloc(n*sizeof(int));
        dt->size = n;
        dt->count = 0;
        return dt;
}

void print_array(int array[], int size)
{
        printf("\n");

        for(int i = 0; i < size; i++)
                printf("  %d",array[i]);

        printf("\n");
}

/*
 * Insert an element at the end of the dynamic table
 * When a new element is to be inserted, but there is no more space
 * left in the dynamic table, increase the size of the dynamic table
 * by a factor of 1.5.
 * @dyntable:   double pointer to the dynamic table
 * @element:    element to be inserted
 */
void push_back(void **dyntable, int element)
{
        struct dyntable* dt_temp = (struct dyntable*) *dyntable;

        printf("\npush_back");
        /*
         * The dynamic table is full. Time to expand the dynamic table.
         */
        if(dt_temp->count == dt_temp->size) {
                int new_size = (int) ceil(dt_temp->size*INCREASE_FACTOR);
                printf(": resize - %d\n",new_size);
                dt_temp->data = (int *)realloc(dt_temp->data, sizeof(int)*new_size);
                dt_temp->size = new_size;
        }

        *(dt_temp->data + dt_temp->count++) = element;

        print_array(dt_temp->data, dt_temp->count);
        return;
}


/*
 * Pops element from the end of dynamic table.
 * If the load factor of the dynamic table becomes equal to, or 
 * drops below the threshold of 0.25, then the dynamic table must 
 * be shrunk by 0.25 times its * initial size, and then increased 
 * by 1.5 times the new size.
 * @dyntable:   double pointer to the dynamic table
 */
void pop_back(void **dyntable)
{
        struct dyntable* dt_temp = (struct dyntable*) *dyntable;
        printf("\npop_back");
        /*
         * Dynamic table is empty. pop_back operation is invalid.
         */ 
        if(!dt_temp->count){
                printf("\n pop_back is invalid. all elements have been exhausted.\n");
                return;
        }

        float load_factor = ((float)(--dt_temp->count))/((float)dt_temp->size);

        /*
         * Load factor of the dynamic table has become less than/equal
         * to threshold. Dynamic table must be resized.
         */
        if(load_factor <= DECREASE_FACTOR){
                int new_size = (int) ceil(dt_temp->size*DECREASE_FACTOR*INCREASE_FACTOR);
                dt_temp->data = (int *)realloc(dt_temp->data, sizeof(int)*new_size);
                dt_temp->size = new_size;
        }

        print_array(dt_temp->data, dt_temp->count);
        return;
}