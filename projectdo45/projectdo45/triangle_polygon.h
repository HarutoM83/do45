#pragma once
#include"Dx12.h"
#include"command_list.h"
class triangle_polygon final
{
public:
    
    triangle_polygon() = default;

    
    ~triangle_polygon();

    
    [[nodiscard]] bool create(const Dx12& device) noexcept;

    [[nodiscard]] void draw(const command_list& commandList) noexcept;


private:
    
    [[nodiscard]] bool createVertexBuffer(const Dx12& device) noexcept;

   
    [[nodiscard]] bool createIndexBuffer(const Dx12& device) noexcept;

private:
    ID3D12Resource* vertexBuffer_{};  /// 頂点バッファ
    ID3D12Resource* indexBuffer_{};   /// インデックスバッファ

    D3D12_VERTEX_BUFFER_VIEW vertexBufferView_ = {};  ///< 頂点バッファビュー
    D3D12_INDEX_BUFFER_VIEW  indexBufferView_ = {};  ///< インデックスバッファビュー
};



