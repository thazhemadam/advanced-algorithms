#include "dyntable_impl.h"

#define BENCHMARK_COUNT 100

/*
 * Start a nanosecond-resolution timer
 */
struct timespec timer_start(void)
{
	struct timespec start_time;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
	return start_time;
}

/*
 * End a timer, returning nanoseconds elapsed as a long
 * NOTE: time_end must be called ONLY after timer_start has been called.
 */
long timer_end(struct timespec start_time)
{
	struct timespec end_time;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);
	long diffInNanos = (end_time.tv_sec - start_time.tv_sec) * (long)1e9 + (end_time.tv_nsec - start_time.tv_nsec);
	return diffInNanos;
}

int main(void)
{
	void *dt = (struct dyntable*) make_new_dynamic_table(3);

	if(!dt)
		goto exit;

	printf("Size of dyntable:%lu\n", sizeof(dt));

	for (int i = 1; i <= BENCHMARK_COUNT; ++i) {
		struct timespec vartime = timer_start();

		if (rand() % 2)
			push_back(&dt, random() % BENCHMARK_COUNT);

		else
			pop_back(&dt);

		long time_elapsed_nanos = timer_end(vartime);
		printf("Time elapsed: %ld\n", time_elapsed_nanos);
	}
	free(dt);
exit:
	return 0;
}