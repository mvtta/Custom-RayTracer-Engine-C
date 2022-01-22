#version 300 es



pvec3 lightDir = vec3(0.0);

float atten = CalcAttenuation(cameraSpacePosition, lightDir);

vec4 attenIntensity = atten * lightIntensity;
	
vec3 surfaceNormal = normalize(vertexNormal);
float cosAngIncidence = dot(surfaceNormal, lightDir);
cosAngIncidence = clamp(cosAngIncidence, 0, 1);
	
vec3 viewDirection = normalize(-cameraSpacePosition);
	
vec3 halfAngle = normalize(lightDir + viewDirection);

float blinnTerm = dot(surfaceNormal, halfAngle);

blinnTerm = clamp(blinnTerm, 0, 1);
blinnTerm = cosAngIncidence != 0.0 ? blinnTerm : 0.0;
blinnTerm = pow(blinnTerm, shininessFactor);

outputColor = (diffuseColor * attenIntensity * cosAngIncidence) +
    (specularColor * attenIntensity * blinnTerm) +
    (diffuseColor * ambientIntensity);

