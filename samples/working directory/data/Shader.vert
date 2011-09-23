// a simple shader to make things bounce on the y axis
attribute vec4 color;

varying vec4 colorVarying;

uniform float translate;

void main()
{
	gl_Position = ftransform();
	gl_Position.y += sin(translate) / 2.0;
	
	colorVarying = color;
}
