uniform sampler2D texture;
uniform vec4 color;
uniform float coloredLayerOffset;
uniform float topLayerOffset;
uniform float opacity;

void main() {
    // vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
    vec2 onePixel = vec2(1.0, 0.0) / textureSize(texture, 0);
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    vec4 colorLayerPixel = texture2D(texture, gl_TexCoord[0].xy + onePixel*coloredLayerOffset);

    vec4 topLayerPixel = texture2D(texture, gl_TexCoord[0].xy + onePixel*topLayerOffset);

    // multiply it by the color
    gl_FragColor = 
    // pixel
    //  + color * colorLayerPixel + topLayerPixel;
    // vec4 finalColor = 
          pixel * (1 - colorLayerPixel.a) * (1 - topLayerPixel.a) * opacity
        + color * colorLayerPixel * colorLayerPixel.a * (1 - topLayerPixel.a) * opacity
        + topLayerPixel * topLayerPixel.a * opacity;
        // + color * colorLayerPixel + topLayerPixel;
    // gl_FragColor = finalColor;
}