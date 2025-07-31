#version 410 core

layout(location = 0) out vec4 color;

in vec2 v_UV;

uniform float u_Time;

const vec3 COLOR_1 = vec3(0.439, 0.22, 0.471);
const vec3 COLOR_2 = vec3(0.2, 0.459, 0.435);
const vec3 COLOR_3 = vec3(0.588, 0.353, 0.529);

const float N = 4.5636;
const float SPEED = 0.1; 

void main()
{
    float k1 = (v_UV.x + u_Time * SPEED) * N;
    vec3 res_gr = mix(COLOR_1, COLOR_2, sin(k1));

    float k2 = (v_UV.x * v_UV.y + u_Time * SPEED) * N;
    vec3 out_color = mix(res_gr, COLOR_3, sin(k2));

    color = vec4(out_color, 1.0);
}