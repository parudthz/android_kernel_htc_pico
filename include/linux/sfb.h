enum {
        TCA_SFB_UNSPEC,
        TCA_SFB_PARMS,
        __TCA_SFB_MAX,
};

#define TCA_SFB_MAX (__TCA_SFB_MAX - 1)

/*
 * Note: increment, decrement are Q0.16 fixed-point values.
 */
struct tc_sfb_qopt {
        __u32 rehash_interval;  /* delay between hash move, in ms */
        __u32 warmup_time;      /* double buffering warmup time in ms (warmup_time < rehash_interval) */
        __u32 max;              /* max len of qlen_min */
        __u32 bin_size;         /* maximum queue length per bin */
        __u32 increment;        /* probability increment, (d1 in Blue) */
        __u32 decrement;        /* probability decrement, (d2 in Blue) */
        __u32 limit;            /* max SFB queue length */
        __u32 penalty_rate;     /* inelastic flows are rate limited to 'rate' pps */
        __u32 penalty_burst;
};

struct tc_sfb_xstats {
        __u32 earlydrop;
        __u32 penaltydrop;
        __u32 bucketdrop;
        __u32 queuedrop;
        __u32 childdrop; /* drops in child qdisc */
        __u32 marked;
        __u32 maxqlen;
        __u32 maxprob;
        __u32 avgprob;
};

#define SFB_MAX_PROB 0xFFFF
