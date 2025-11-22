#include "descriptor_heap.h"
#include <cassert>

descriptor_heap::~descriptor_heap() {
    // ディスクリプタヒープの解放
    if (heap_) {
        heap_->Release();
        heap_ = nullptr;
    }
}



