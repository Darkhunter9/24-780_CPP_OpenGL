float prevColor[4];
	glGetFloatv(GL_CURRENT_COLOR, prevColor);

// code code code where the color is set to some other value(s)

	glColor4f(prevColor[0], prevColor[1], prevColor[2], prevColor[3]);