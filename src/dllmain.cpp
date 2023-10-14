#pragma comment(lib, "../SDK/lib/bedrock_server_api.lib")
#pragma comment(lib, "../SDK/lib/bedrock_server_var.lib")
#pragma comment(lib, "../SDK/lib/SymDBHelper.lib")
#pragma comment(lib, "../SDK/lib/LiteLoader.lib")

#include <llapi/HookAPI.h>
#include <llapi/mc/Block.hpp>
#include <llapi/mc/BlockSource.hpp>
#include <llapi/mc/BlockPos.hpp>

TInstanceHook(void, "?onRemove@Block@@QEBAXAEAVBlockSource@@AEBVBlockPos@@@Z", Block, BlockSource* a2, BlockPos* a3) {
    if (getTypeName() == "minecraft:sniffer_egg") {
        a2->removeFromRandomTickingQueue(*a3, *this);
    }
    return original(this, a2, a3);
}
