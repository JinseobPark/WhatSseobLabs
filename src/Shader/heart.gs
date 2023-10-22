#version 330 core
layout (points) in;
layout (line_strip, max_vertices = 30) out;

in VS_OUT {
    vec3 color;
} gs_in[];

out vec3 fColor;

uniform float time_ = 1.0f;

void build_house(vec4 position)
{    
    fColor = gs_in[0].color; // gs_in[0] since there's only one input vertex
    gl_Position = position + vec4(-0.2, -0.2, 0.0, 0.0); // 1:bottom-left   
    EmitVertex();   
    gl_Position = position + vec4( 0.2, -0.2, 0.0, 0.0); // 2:bottom-right
    EmitVertex();
    gl_Position = position + vec4(-0.2,  0.2, 0.0, 0.0); // 3:top-left
    EmitVertex();
    gl_Position = position + vec4( 0.2,  0.2, 0.0, 0.0); // 4:top-right
    EmitVertex();
    gl_Position = position + vec4( 0.0,  0.4, 0.0, 0.0); // 5:top
    fColor = vec3(1.0, 1.0, 1.0);
    EmitVertex();
    EndPrimitive();
}

void build_heart(vec4 position)
{
    fColor = gs_in[0].color; // gs_in[0] since there's only one input vertex
    const float pi = 3.14159265;
    
    for (int i = 0; i < 30; i++)
    {
        float time_cover = time_ + 0.2f;// clamp(time_, 0.2f, 1.0f);
        float angle = 2 * pi * (float(i) / 30.0);
        float x = 16.0 * sin(angle) * sin(angle) * sin(angle);
        float y = 13.0 * cos(angle) - 5 * cos(2*angle) - 2 * cos(3*angle) - cos(4*angle);
        gl_Position = position + time_cover * 0.01 * vec4(x, y, 0.0, 0.0);
        EmitVertex();
    }

    EndPrimitive();
}

void main() {    
    //build_house(gl_in[0].gl_Position);
    build_heart(gl_in[0].gl_Position);
}