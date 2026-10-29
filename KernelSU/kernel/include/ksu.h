#ifndef __KSU_H_KSU
#define __KSU_H_KSU

#include <linux/types.h>
#include <linux/cred.h>
#include <linux/workqueue.h>

#ifndef KSU_VERSION_TAG
#define KSU_VERSION_TAG "v3.4.2"
#endif

#define KERNEL_SU_VERSION KSU_VERSION
#define KERNEL_SU_VERSION_TAG KSU_VERSION_TAG

extern struct cred *ksu_cred;
extern bool allow_shell;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0)
extern struct selinux_policy *backup_sepolicy;
#endif
extern bool ksu_no_custom_rc;

static inline int startswith(char *s, char *prefix)
{
    return strncmp(s, prefix, strlen(prefix));
}

static inline int endswith(const char *s, const char *t)
{
    size_t slen = strlen(s);
    size_t tlen = strlen(t);
    if (tlen > slen)
        return 1;
    return strcmp(s + slen - tlen, t);
}

#endif
