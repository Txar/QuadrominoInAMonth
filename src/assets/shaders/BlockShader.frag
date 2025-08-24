uniform sampler2D texture;
uniform vec4 color;
uniform float coloredLayerOffset;
uniform float topLayerOffset;
// uniform int fieldHeight;
uniform int fieldHeight;
uniform int blockY;

// float roundTo(float x, float base) {
//     return floor(x / base) * base
// }

float capAt(float x, float cap) {
    if (x > cap) {
        return cap;
    } else {
        return x;
    }
}

void main() {
    vec2 onePixel = vec2(1.0, 0.0) / textureSize(texture, 0);
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    vec4 colorLayerPixel = texture2D(texture, gl_TexCoord[0].xy + onePixel*coloredLayerOffset);

    vec4 topLayerPixel = texture2D(texture, gl_TexCoord[0].xy + onePixel*topLayerOffset);

    vec4 finalColor = 
          pixel * (1 - colorLayerPixel.a) * (1 - topLayerPixel.a)
        + color * colorLayerPixel * colorLayerPixel.a * (1 - topLayerPixel.a)
        + topLayerPixel * topLayerPixel.a;

    float falloffMultiplier = 2.0 - capAt(float(blockY + 5.0), float(fieldHeight)) / (float(fieldHeight));
    finalColor = finalColor / falloffMultiplier;
    finalColor[3] = 1.0;
    
    gl_FragColor = finalColor;
} 