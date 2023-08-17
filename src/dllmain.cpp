#pragma comment(lib, "../SDK/lib/bedrock_server_api.lib")
#pragma comment(lib, "../SDK/lib/bedrock_server_var.lib")
#pragma comment(lib, "../SDK/lib/SymDBHelper.lib")
#pragma comment(lib, "../SDK/lib/LiteLoader.lib")

#include <llapi/HookAPI.h>
#include <llapi/mc/BlockPos.hpp>

std::list<BlockPos> list{};

TClasslessInstanceHook(void, "?onPlace@SnifferEggBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@@Z", void* a2, BlockPos* a3) {
    if (std::find(list.begin(), list.end(), *a3) != list.end()) {
        list.remove(*a3);
        return;
    }
    original(this, a2, a3);
}

TClasslessInstanceHook(bool, "?_attachedBlockWalker@PistonBlockActor@@AEAA_NAEAVBlockSource@@AEBVBlockPos@@EE@Z", void* a2, BlockPos* a3, unsigned char a4, unsigned char a5) {
    list.push_back(*a3);
    return original(this, a2, a3, a4, a5);
}
