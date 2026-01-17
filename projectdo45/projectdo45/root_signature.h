#pragma once
#include"Dx12.h"
class root_signature final
{
public:
    
    root_signature() = default;

    
    ~root_signature();

    
    [[nodiscard]] bool create(const Dx12& device) noexcept;

    
    [[nodiscard]] ID3D12RootSignature* get() const noexcept;

private:
    ID3D12RootSignature* rootSignature_{};  /// ルートシグネチャ
};

