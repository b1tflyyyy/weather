#version 410 core

layout(location = 0) out vec4 color;

in vec2 v_UV;

uniform float u_Time;

const float N = 4.5636;
const float SPEED = 0.1; 

uniform vec3 u_Color_1;
uniform vec3 u_Color_2;
uniform vec3 u_Color_3;

void main()
{
    float k1 = (v_UV.x + u_Time * SPEED) * N;
    vec3 res_gr = mix(u_Color_1, u_Color_2, sin(k1));

    float k2 = (v_UV.x * v_UV.y + u_Time * SPEED) * N;
    vec3 out_color = mix(res_gr, u_Color_3, sin(k2));

    color = vec4(out_color, 1.0);
}