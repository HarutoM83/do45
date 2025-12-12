#pragma once
#include"Dx12.h"
#include"shader.h"
#include "root_signature.h"

class pipline_state_object final
{
public:
    
    pipline_state_object() = default;

    
    ~pipline_state_object();

    
    [[nodiscard]] bool create(const Dx12& device, const shader& shader, const root_signature& rootSignature) noexcept;

    
    [[nodiscard]] ID3D12PipelineState* getp() const noexcept;

private:
    ID3D12PipelineState* pipelineState_ = {};  ///< パイプラインステート
};

