What is a resource?
- External data loaded/saved by an application.
- E.G. audio clip, font, image, model (animation clip/curve/keyframe, material, mesh, transform), nurbs, video clip...

What is a resource description?
- The information necessary to load/save a resource from file/web (e.g. a filename, a url, ...).

What is a resource load(er)?
- A single stateless function for loading resources from file/web to be implemented for each resource - description pair.

What is a resource save(r)?
- A single stateless function for saving  resources to   file/web to be implemented for each resource - description pair (optional).

What is a resource container?
- A vector of a specific resource type, using pool allocation.
- Why use a non-standard container? To store resources efficiently:
  - Use a contiguous data structure for faster iteration and cache coherency.
  - Use a (stateful) pool memory allocation scheme for faster creation and deletion.

What is a resource registry?
- A compile-time specified tuple where each element is a resource container: 
  `registry<audio_clip, font, image, model, nurbs, video_clip> resource_registry;`
- Provides access to the resource containers by type: 
  `auto& fonts = resource_registry.get<font>();`

What is a central resource registry?
- A singleton resource registry.
