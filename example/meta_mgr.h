#pragma once

#include <map>
#include <memory>

#include "kv_string.h"
#include "file_io.h"

class MetaMgr {
public:
    bool Init(const char * dir);

    void Set(const KVString & key, uint64_t pos);

    uint64_t Get(const KVString & key);

protected:
    int RestoreMeta();

    //获取文件路径
    static KVString GetPath(KVString &dir, const char * name) {
        KVString path = dir;
        path = path + name;
        return path;
    }

private:
    std::map<KVString, uint64_t> keys_map_;//存储key对应的存储位置

    std::unique_ptr<FileIo> key_fh_;

    KVString dir_;
};
