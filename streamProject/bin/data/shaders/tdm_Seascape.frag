#define pi 3.14159

float glow(float x, float str, float dist){
    return dist / pow(x, str);
}

// Sinus Signed Distance Function (distance field)
float sinSDF(vec2 st, float A, float offset, float f, float phi){
    return abs((st.y - offset) + sin(st.x * f + phi) * A);
}

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    vec2 st = (fragCoord-0.5*iResolution.xy) / iResolution.y + 0.5;
    float col = 0.0;
    float time = iTime/2.0;
    float str = 0.6; // Strength of the light
    float dist = 0.02; // Light propagation distance
    float nSin = 4.0; // Number of sinus functions drawn
  
    
    float timeHalfInv = -time * sign(st.x-0.5);
    float am = cos(st.x*3.0); // Amplitude modulation
    float offset = 0.5+sin(st.x*12.0+time)*am*0.05;
    for(float i = 0.0; i<nSin ; i++){
        col += glow(sinSDF(st, am*0.2, offset, 6.0, timeHalfInv+i*2.0*pi/nSin), str, dist);
    }
    
    // Reverse the color on one half of the screen
    vec3 s = cos( 6.*st.y*vec3(1,2,3) - time*vec3(1,-1,1) ) * 0.5;
    float cut = st.x+ (s.x+s.y+s.z) / 33.0;
    col = abs(smoothstep(-0.01,-0.03,0.5-cut) - clamp(col,0.0,1.0));
	
    
    // Output to screen
    fragColor = vec4(vec3(col),1.0);
    
    //----------------------------------------------
    
    // Test glow function with a circle distance field
    	/*
        float circleSDF = length(st-0.5);
        fragColor = vec4(vec3(glow(circleSDF, 1.0, 0.02)), 1.0);
		*/
    
    // Test sinus distance field function
        // fragColor = vec4(vec3(sinSDF(st, 0.1, 0.5, 10.0, 0.0)),1.0); // horizontal
        // fragColor = vec4(vec3(sinSDF(st.yx, 0.1, 0.5, 10.0, 0.0)),1.0); // vertical
}