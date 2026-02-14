#pragma once
#include"Dx12.h"
class shader final
{
public:
    
    shader() = default;
        
    ~shader();
        
    [[nodiscard]] bool create(const Dx12& device) noexcept;
        
    [[nodiscard]] ID3DBlob* vertexShader() const noexcept;
        
    [[nodiscard]] ID3DBlob* pixelShader() const noexcept;

private:
    ID3DBlob* vertexShader_{};  /// 頂点シェーダ
    ID3DBlob* pixelShader_{};   /// ピクセルシェーダ
};

